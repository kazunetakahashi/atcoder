#
# File    : A.rb
# Author  : Kazune Takahashi
# Created : 3/3/2019, 8:55:00 PM
# Powered by Visual Studio Code
#

a, b, c = gets.chomp.split(" ").map{|i| i.to_i}
puts [c, b/a].min
