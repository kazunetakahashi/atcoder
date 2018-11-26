#
# File    : A.rb
# Author  : Kazune Takahashi
# Created : 11/26/2018, 11:38:28 PM
# Powered by Visual Studio Code
#

a, b, c, d = gets.chomp.split(" ").map{|i| i.to_i}
puts [a * b, c * d].max
