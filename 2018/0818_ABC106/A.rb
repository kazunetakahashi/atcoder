#
# File    : A.rb
# Author  : Kazune Takahashi
# Created : 8/18/2018, 8:51:00 PM
# Powered by Visual Studio Code
#

a, b = gets.chomp.split(" ").map{|i| i.to_i}
puts (a - 1) * (b - 1)
