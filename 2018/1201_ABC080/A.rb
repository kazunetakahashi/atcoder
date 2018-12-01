#
# File    : A.rb
# Author  : Kazune Takahashi
# Created : 2018-12-1 22:20:51
# Powered by Visual Studio Code
#

n, a, b = gets.chomp.split(" ").map{|i| i.to_i}
puts [n * a, b].min
