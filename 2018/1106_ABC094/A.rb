#
# File    : A.rb
# Author  : Kazune Takahashi
# Created : 2018-11-6 21:45:02
# Powered by Visual Studio Code
#

a, b, x = gets.chomp.split(" ").map{|i| i.to_i}
if 0 <= x && x <= b
  puts "Yes"
else
  puts "No"
end
