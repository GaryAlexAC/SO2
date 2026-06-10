#include <linux/init.h>     // Para las macros __init y __exit
#include <linux/kernel.h>   // Para printk y KERN_INFO
#include <linux/module.h>   // Para la funcionalidad de módulos

static char* message = "Hola mundo";
static int counter  =1;

module_param(counter, int, S_IRUGO);
module_param(message, charp, S_IRUGO)

static int __init m_init(void)
{
    pr_debug("Modulo de pruebas cargado\n");
    for(int i =0; i< counter; ++i){
        pr_info("#%d | %s\n", i, message);
    }
    return 0;
}

static void __exit m_exit(void){
    printk(KERN_DEBUG "Módulo de pruebas descargado\n");
}

module_init(m_init);
module_exit(m_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("SOPES2");
MODULE_DESCRIPTION("Módulo de hola mundo con parámetros");
MODULE_VERSION("1.0");