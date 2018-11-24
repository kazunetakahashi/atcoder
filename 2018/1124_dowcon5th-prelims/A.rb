#
# File    : A.rb
# Author  : Kazune Takahashi
# Created : 11/24/2018, 8:03:06 PM
# Powered by Visual Studio Code
#

n = gets.to_i
a = gets.chomp.split(" ").map{|i| i.to_i}

sum = a.inject(:+)

ave = sum/n.to_f

dist = 2 * n
num = 0

for i in 0...a.size
  if dist > (a[i] - ave).abs
    dist = (a[i] - ave).abs
    num = i
  end
end

puts num
