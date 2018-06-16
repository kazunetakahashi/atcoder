#
# File    : D.rb
# Author  : Kazune Takahashi
# Created : 2018-6-16 21:07:15
# Powered by Visual Studio Code
#

n, m = gets.chomp.split(" ").map{|u| u.to_i}
x = []
y = []
z = []
n.times{
  s, q, r = gets.chomp.split(" ").map{|u| u.to_i}
  x << s
  y << q
  z << r
}

sum = []

for i in 0...n
  sum << x[i] + y[i] + z[i]
end

sum = sum.sort.reverse

ans = 0

for i in 0...m
  ans += sum[i]
end

puts ans