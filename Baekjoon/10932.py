#!/usr/bin/env python3
from hashlib import sha512
s = input().encode()
print(sha512(s).hexdigest())