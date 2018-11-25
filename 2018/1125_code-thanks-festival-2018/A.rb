#
# File    : A.rb
# Author  : Kazune Takahashi
# Created : 11/25/2018, 11:40:00 AM
# Powered by Visual Studio Code
#

t, a, b, c, d = gets.chomp.split(" ").map{|i| i.to_i}

ans = 0
if t >= c
  ans += d
  t -= c
end
if t >= a
  ans += b
  t -= a
end

puts ans