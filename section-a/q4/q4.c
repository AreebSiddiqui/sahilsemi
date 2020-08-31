
#include <linux/kernel.h>
#include <linux/errno.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/netdevice.h>
#include <linux/etherdevice.h>
#include <linux/ethtool.h>
#include <linux/skbuff.h>
#include <linux/slab.h>
#include <linux/of.h>
#include <linux/platform_device.h>

/* 
    The struct net_devices is the structure by which any New device is represented in the kernel. It is the interface by which data transmit takes place.
 */
struct net_device *sn0;
int fake_eth_open(struct net_device *dev)
{
    printk("fake_eth_open called\n");
    /* We are now ready to accept transmit requests from
* the queueing layer of the networking.
*/
    netif_start_queue(dev);
    return 0;
}

int fake_eth_release(struct net_device *dev)
{
    pr_info("fake_eth_release called\n");
    netif_stop_queue(dev);
    return 0;
}
int fake_eth_xmit(struct sk_buff *skb, struct net_device *ndev)
{
    pr_info("dummy xmit called...\n");
    // ndev->stats.tx_bytes += skb->len;
    // ndev->stats.tx_packets++;
    dev_kfree_skb(skb);
    return NETDEV_TX_OK;
}
int fake_eth_init(struct net_device *dev)
{
    pr_info("fake eth device initialized\n");
    return 0;
}

static const struct net_device_ops my_netdev_ops = {
    .ndo_init = fake_eth_init,
    .ndo_open = fake_eth_open,
    .ndo_stop = fake_eth_release,
    .ndo_start_xmit = fake_eth_xmit,
};

static void virtual_setup(struct net_device *dev)
{
    dev->netdev_ops = &my_netdev_ops;
}

int rtl8139_init_module(void)
{
    int result;
    sn0 = alloc_netdev(0, "virtnC%d", sn0, virtual_setup);
    if ((result = register_netdev(sn0)))
    {
        printk("sn0: Error %d initalizing card ...", result);
        return result;
    }
    return 0;
}

void rtl8139_cleanup(void)
{
    printk("Cleaning Up the Module\n");
    unregister_netdev(sn0);
    return;
}

module_init(rtl8139_init_module);
module_exit(rtl8139_cleanup);