# This Source Code Form is subject to the terms of the Mozilla Public
# License, v.2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at https://mozilla.org/MPL/2.0/.

"""
repl module provides an ability to interact with the backend via command line.
To run it, use one command per line as follows:
    get [key]
        or
    set [key] [values...]
"""

import sys
from embeddingstore import EmbeddingStoreClient

# When run, it takes a command per line:
# Either:
# get [space] [key]
# OR
# set [space] [key] [values...]
if __name__ == '__main__':
    client = EmbeddingStoreClient()
    for line in sys.stdin:
        line = line.rstrip()
        tokens = line.split()
        if len(tokens) < 3:
            print("INVALID COMMAND")
        cmd = tokens[0]
        space = tokens[1]
        key = tokens[2]
        if cmd == "get":
            print(client.get(space, key))
        elif cmd == "set":
            val = [float(tok) for tok in tokens[3:]]
            client.set(space, key, val)
            print("SUCCESS")
        elif cmd == "nn":
            num = int(tokens[3])
            print(client.nearest_neighbor(space, key, num))
        else:
            print("UNKNOWN COMMAND")
