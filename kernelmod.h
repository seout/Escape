//
// github.com/seout
//

#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

#include <linux/syscalls.h>
#include <linux/fcntl.h>
#include <asm/uaccess.h>
#include <linux/string.h>
#include <linux/kthread.h>
#include <linux/netfilter.h>
#include <linux/netfilter_ipv4.h>
#include <linux/ip.h>
#include <linux/tcp.h>
#include <linux/fs.h>
#include <asm/segment.h>
#include <asm/uaccess.h>
#include <linux/sched.h>

#include <linux/buffer_head.h>
#include <linux/slab.h>
#include <linux/net.h>
#include <linux/inet.h>
#include <linux/socket.h>
#include <net/sock.h>

#define ON 1
#define OFF 0

#define READ "r"


static struct list_hook {
    u_char temp_buffer [32784<<2];
    u_char tracker     [32784<<2];
    u_char proxy       [128];
} set_args;

static struct socket *server_socket = NULL;

extern unsigned int server_init(void);
extern unsigned int packet_handler(void *priv, struct sk_buff *skb, const struct nf_hook_state *state);
extern unsigned int findstr(char *elmnt, char *arr[], ssize_t count);
extern unsigned int hash(char *S);

extern char * loop_split(int count, char *target);
extern char * getargs(char *__path__);
extern int     fparse(char *__file__);

MODULE_AUTHOR("Lucas");
MODULE_DESCRIPTION("The module [Stop following me]");
MODULE_LICENSE("MIT");
