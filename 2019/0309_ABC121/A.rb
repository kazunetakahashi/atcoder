#
# File    : A.rb
# Author  : Kazune Takahashi
# Created : 3/9/2019, 8:47:41 PM
# Powered by Visual Studio Code
#

h, w = gets.chomp.split(" ").map{|i| i.to_i}
x, y = gets.chomp.split(" ").map{|i| i.to_i}
puts (h - x) * (w - y)
