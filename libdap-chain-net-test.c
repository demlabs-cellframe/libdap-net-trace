#include <stdio.h>

#include "dap_config.h"
#include "dap_chain_net.h"
#include "iputils/ping.h"

int main() //int argc, char **argv)
{
    const char *ip = "192.168.2.2";
    int repeat = 3;
//    dap_common_init("net-test.log");
//    dap_config_init("./dist");
//    dap_chain_net_init();
    int res = ping_util(ip, repeat);
    printf("ping_util()=%d\n", res);
    return 0;
}
