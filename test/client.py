#!/usr/bin/env python3

import socket

sk = socket.socket()

sk.connect(("127.0.0.1", 6314))
sk.send(bytes("Nihao wo shi luojiayi", "utf-8"))
sk.send(bytes("zhe shi wo di yi ci fa song!", "utf-8"))
sk.close()
