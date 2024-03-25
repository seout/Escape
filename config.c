
#include "kernelmod.h"


unsigned int packet_handler(void *priv, struct sk_buff *skb, const struct nf_hook_state *state) {

    struct iphdr *ip_header = (struct iphdr *)skb_network_header(skb);
//    struct tcphdr *tcp_header;

    char ip_address[16];
    unsigned char *data;
    int data_len;

    char *blackl[5] = {
            "1.1.1.1",
            "37.140.241.9",
            "1.1.1.2",
            "1.1.1.3",
            "1.1.1.4"
    };

    data = skb->data;
    data_len = skb->len;

    if (ip_header) {
        snprintf(ip_address, sizeof(ip_address), "%pI4", &ip_header->saddr);
    }


    for (int i = 0; i < 6; i++) {
        if (findstr(ip_address, blackl, 5)) {
            printk(KERN_INFO "[The host is blocked: %s]\n", ip_address);
            return NF_DROP;
        }
    }

    printk(KERN_INFO "[IP]: %s\n", ip_address);

    return NF_ACCEPT;
}

unsigned int hash(char *S) {
    int r=0;
    while(*S) {
        r+=(int)(*S);
        S++;
    }
    return r;
}

unsigned int findstr(char *elmnt, char *arr[], ssize_t count) {

    for (int i = 0; i < count; i++) {
        if (hash(elmnt) == hash(arr[i])) {
            return 1;
        }
    }

    return 0;
}

