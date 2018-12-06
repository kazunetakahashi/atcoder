#
# File    : C.rb
# Author  : Kazune Takahashi
# Created : 12/6/2018, 11:10:15 PM
# Powered by Visual Studio Code
#

n, x = gets.chomp.split(" ").map{|i| i.to_i}
a = gets.chomp.split(" ").map{|i| i.to_i}
ans = 0
if a[0] > x
  ans = a[0] - x
  a[0] = x
end
for i in 1...n
  t = a[i-1] + a[i] - x
  if t > 0
    ans += t
    a[i] -= t
  end
end

puts ans
