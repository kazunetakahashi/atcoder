#
# File    : A.rb
# Author  : Kazune Takahashi
# Created : 2018-11-6 21:45:02
# Powered by Visual Studio Code
#

a, b, x = gets.chomp.split(" ").map{|i| i.to_i}
if a <= x && x <= a + b
  puts "YES"
else
  puts "NO"
end
