#include "ping_pong.h"
#include <msg.h>
#include <stdio.h>
#include <string.h>

union MSG {
        struct ping ping;
        struct pong pong;
};

static void send_ping(uint64_t pid)
{
        const char str[] = "Hello pong";
        union MSG *msg;

        msg = msg_alloc(sizeof(struct ping), PING);
        memcpy(msg->ping.str, str, sizeof(str));
        msg_send(msg, pid);
}

int main(void)
{
        uint64_t rx[] = {0};
        union MSG *msg;
	uint64_t type;
        uint64_t pid;

        msg_init("ping", NULL);
        msg_hunt_async("pong", NULL, NULL);

        for (;; ) {
		msg = msg_recv(rx);
                pid = msg_sender(msg);
		type = msg_type(msg);
                switch (type) {
                case PONG:
                        printf("%s (%zu)\n", msg->ping.str, pid);
                        send_ping(pid);
                        break;
                case MSG_HUNT:
                        printf("pong found (%zu)\n", pid);
                        msg_attach(pid, NULL, NULL);
                        send_ping(pid);
                        break;
                case MSG_ATTACH:
                        printf("lost connection to pong (%zu)\n", pid);
                        msg_hunt_async("pong", NULL, NULL);
                        break;
                default:
                        break;
                }
                msg_free(msg);
                msg_delay(500);
        }
}
