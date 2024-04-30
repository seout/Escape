
//
// github.com/webnefor
// (c) Lucas
//
#include "kernelmod.h"

static struct nf_hook_ops nfho;


static int __init kmain(void) 
{
    nfho.hook = packet_handler;
    nfho.hooknum = NF_INET_PRE_ROUTING;
    nfho.pf = PF_INET;
    nfho.priority = NF_IP_PRI_FIRST;

    nf_register_net_hook(&init_net, &nfho);

    return 0;
}


static void __exit kclose(void) 
{

    nf_unregister_net_hook(&init_net, &nfho);
}


module_init(kmain);
module_exit(kclose);
