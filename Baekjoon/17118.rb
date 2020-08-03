#!/usr/bin/env ruby
# xp == a * x0 + b (mod p) by diagonalization
# p | a * x0 + b - xp = 998244359987710471 = 998244353 * 1000000007
x0 = gets.to_i
a = 860798509
b = 198609463
p = 1000000007
xp = (a * x0 + b) % p
print xp
