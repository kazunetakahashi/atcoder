#
# File    : A.rb
# Author  : Kazune Takahashi
# Created : 4/13/2019, 8:50:21 PM
# Powered by Visual Studio Code
#

a, b = gets.chomp.split(" ").map{|i| i.to_i}
puts [a + (a-1), b + (b - 1), a + b].max
