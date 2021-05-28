linear-probing
0.10-> 1.061185
0.20-> 1.128852
0.30-> 1.215892
0.40-> 1.335498
0.50-> 1.500595
0.60-> 1.751015
0.70-> 2.165027
0.80-> 2.994666
0.90-> 5.393106
quadratic-probing
0.10-> 1.064776
0.20-> 1.130199
0.30-> 1.211597
0.40-> 1.315075
0.50-> 1.438952
0.60-> 1.604509
0.70-> 1.823949
0.80-> 2.165034
0.90-> 2.786355
separate-chaining
0.10-> 1.096866
0.20-> 1.191696
0.30-> 1.302345
0.40-> 1.432270
0.50-> 1.581487
0.60-> 1.770325
0.70-> 2.012965
0.80-> 2.375864
0.90-> 3.017657

Even with the garbage array, the hash table insertion is quick with all the 3 implementations doing them in approximately constant time on average cases.
I saw that linear probing was slightly faster than chain hashing, but as load factor increased performance of linear probing decreased much rapidly.
Quadratic probing is better at resolving primary clusters but it will not work once alpha reaches 0.5 and needs to be rehashed to a larger hash table.