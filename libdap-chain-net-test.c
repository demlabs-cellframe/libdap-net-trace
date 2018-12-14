#include <stdio.h>

#include "dap_config.h"
#include "dap_chain_net.h"
#include "iputils/iputils.h"

int main() //int argc, char **argv)
{
    const char *ip = "ya.ru";
    //const char *ip = "::1";//"2001:4860:4860::8888";//"::1";

//    dap_common_init("net-test.log");
//    dap_config_init("./dist");
//    dap_chain_net_init();


    int repeat = 3;
    int res = ping_util4(ip, repeat);
    printf("ping_util(%s, %d)=%.3lf msec\n", ip, repeat, res / 1000.);
    return 0;
}
