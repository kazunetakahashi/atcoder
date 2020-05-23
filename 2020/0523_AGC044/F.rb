#
# File    : F.rb
# Author  : Kazune Takahashi
# Created : 5/24/2020, 2:40:20 AM
# Powered by Visual Studio Code
#

ary = [1, 1, 1, 7, 4, 1, 336, 384, 334, 220, 108, 36, 6]
n = gets.to_i - 1
if n < ary.size
  puts ary[n]
else
  puts -1
end
