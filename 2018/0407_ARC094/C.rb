#
# File    : C.rb
# Author  : Kazune Takahashi
# Created : 2018-7-23 16:34:50
# Powered by Visual Studio Code
#

a = gets.chomp.split(" ").map{|i| i.to_i}
m = a.max
sum = a.inject(:+)
x = nil
if (3 * m - sum) % 2 == 0
  x = m
else
  x = m + 1
end

puts (3 * x - sum) / 2

