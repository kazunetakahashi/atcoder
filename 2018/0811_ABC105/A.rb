#
# File    : A.rb
# Author  : Kazune Takahashi
# Created : 2018-8-11 20:58:11
# Powered by Visual Studio Code
#

n, k = gets.chomp.split(" ").map{|i| i.to_i}
if n % k == 0
  puts 0
else
  puts 1
end