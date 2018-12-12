#include <stdbool.h>
#include <stdio.h>
#include "dap_chain_net.h"
#include "dap_common.h"

int main()
{
//    dap_common_init("net-test.log");
    dap_config_init("./dist");
    dap_chain_net_init();
    printf("test %d\n", 1);
}
