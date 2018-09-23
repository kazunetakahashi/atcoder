#
# File    : B.rb
# Author  : Kazune Takahashi
# Created : 2018-9-23 21:03:15
# Powered by Visual Studio Code
#

n, m, x, y = gets.chomp.split(" ").map{|i| i.to_i}
k = gets.chomp.split(" ").map{|i| i.to_i}
l = gets.chomp.split(" ").map{|i| i.to_i}
if x < y && k.max < l.min
  puts "No War"
else
  puts "War"
end
