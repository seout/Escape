
//
// github.com/seout
//
#include "kernelmod.h"

static struct nf_hook_ops nfho;


static int __init lkm_example_init(void) 
{
    nfho.hook = packet_handler;
    nfho.hooknum = NF_INET_PRE_ROUTING;
    nfho.pf = PF_INET;
    nfho.priority = NF_IP_PRI_FIRST;

    nf_register_net_hook(&init_net, &nfho);

    return 0;
}


static void __exit lkm_example_exit(void) 
{

    nf_unregister_net_hook(&init_net, &nfho);
}


module_init(lkm_example_init);
module_exit(lkm_example_exit);
