#
# File    : B2.rb
# Author  : Kazune Takahashi
# Created : 2018-12-2 21:33:52
# Powered by Visual Studio Code
#

s = gets.chomp
ans = []
for i in 0...s.size - 2
  ans << (753 - s[i...i + 3].to_i).abs
end
puts ans.min

