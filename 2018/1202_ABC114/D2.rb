#
# File    : D2.rb
# Author  : Kazune Takahashi
# Created : 2018-12-2 21:41:17
# Powered by Visual Studio Code
#

require 'prime'

n = gets.to_i

hash = {}

for i in 2...100
  if i.prime?
    hash[i] = 0
  end
end

for i in 1..n
  i.prime_division.each{|prime, cnt|
    hash[prime] += cnt
  }
end

# p hash

ary = Array.new(100){0}

hash.each{|prime, cnt|
  ary[cnt] += 1
}

98.downto(0){
  hash[i] += hash[i + 1]
}

ans = 0
ans += ary[74]
ans += (ary[4] - 1) * ary[14]
ans += (ary[2] - 1) * ary[24]
ans += (ary[2] - 2) * ary[4] * (ary[4] - 1) / 2

puts ans
