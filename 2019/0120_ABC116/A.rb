#
# File    : A.rb
# Author  : Kazune Takahashi
# Created : 1/20/2019, 8:47:19 PM
# Powered by Visual Studio Code
#

x = gets.chomp.split(" ").map{|i| i.to_i}
x.sort!
puts x[0] * x[1] / 2
