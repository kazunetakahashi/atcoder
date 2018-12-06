#
# File    : B.rb
# Author  : Kazune Takahashi
# Created : 12/6/2018, 11:06:29 PM
# Powered by Visual Studio Code
#

a, b, x = gets.chomp.split(" ").map{|i| i.to_i}
if a == 0
  puts b/x + 1
else
  puts (b/x + 1) - ((a - 1)/x + 1)
end
