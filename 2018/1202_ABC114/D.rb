#
# File    : D.rb
# Author  : Kazune Takahashi
# Created : 2018-12-2 21:13:23
# Powered by Visual Studio Code
#

require 'prime'

n = gets.to_i

hash = {}

for i in 2...100
  if Prime.prime?(i)
    hash[i] = 0
  end
end

for i in 1..n
  num = i
  hash.each{|prime, cnt|
    while num % prime == 0
      num /= prime
      hash[prime] += 1
    end
  }
end

p hash

ary = Array.new(100){0}

hash.each{|prime, cnt|
  ary[cnt] += 1
}

for i in 0...99
  ary[98 - i] += ary[99 - i]
end

ans = 0
ans += ary[74]
ans += ary[4] * ary[14] - ary[14]
ans += ary[2] * ary[24] - ary[24]
ans += (ary[2] - 2) * ary[4] * (ary[4] - 1) / 2

puts ans
