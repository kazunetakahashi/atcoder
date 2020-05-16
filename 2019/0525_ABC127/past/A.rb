#
# File    : A.rb
# Author  : Kazune Takahashi
# Created : 2019-5-25 20:54:47
# Powered by Visual Studio Code
#

a, b = gets.chomp.split(" ").map{|i| i.to_i}
if a <= 5
  puts 0
elsif a <= 12
  puts b/2
else
  puts b
end