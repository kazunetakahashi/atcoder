#
# File    : B.rb
# Author  : Kazune Takahashi
# Created : 2018-12-2 21:01:36
# Powered by Visual Studio Code
#

s = gets.chomp
ans = 10000
for i in 0...s.size
  ans = [ans, (753 - s[i...i+3].to_i).abs].min
end
puts ans

