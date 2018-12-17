#include <stdio.h>
#include <glib.h>
#include <getopt.h>
#include "dap_config.h"
#include "dap_chain_net.h"
#include "iputils/iputils.h"
#include "libdap/test/libdap-test/dap_test.h"

static void usage(void)
{
    fprintf(stderr,
            "\nUsage\n"
                    "  libdap-chain-net-test [options] <destination>\n"
                    "\nOptions:\n"
                    "  -v             verbose mode.\n"
                    "  <destination>  dns name or ip address\n");
    exit(-1);
}

int main(int argc, char **argv)
{
//    dap_common_init("net-test.log");
//    dap_config_init("./dist");
//    dap_chain_net_init();
    bool use_ping_test = false;
    bool use_tracepath_test = true;
    int ch, res;
    char *str;
    while((ch = getopt(argc, argv, "vV")) != EOF) {
        switch (ch) {
        case 'v':
            iputils_set_verbose();
            break;
        case '?':
            //printf("Unknown option '%c'\n",optopt);
            break;
        }
    }
    argc -= optind;
    argv += optind;
    optind = 0;
    if(argc != 1)
        usage();
    const char *ip = argv[0];
//    ip = "ya.ru";
//    ip = "::1";//"2001:4860:4860::8888";//"::1";

    if(use_ping_test) {
        dap_print_module_name("Ping utils");
        int repeat = 3;
        res = ping_util(ip, repeat);
        str = g_strdup_printf("ping_util(\"%s\", repeat=%d) = %.3lf msec", ip, repeat, res / 1000.);
        dap_test_msg(str);
        g_free(str);
        dap_pass_msg("Ping utils");
    }
    if(use_tracepath_test) {
        int hops, dtime_usec;
        dap_print_module_name("Tracepath utils");
        res = tracepath_util(ip, &hops, &dtime_usec);
        str = g_strdup_printf("tracepath_util(\"%s\") = %d hop(s)=%d latency=%.3lf ms", ip, res, hops,
                dtime_usec / 1000.);
        dap_test_msg(str);
        g_free(str);
        dap_pass_msg("Tracepath utils");
    }

    return 0;
}
