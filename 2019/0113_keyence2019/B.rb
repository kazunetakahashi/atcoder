#
# File    : B.rb
# Author  : Kazune Takahashi
# Created : 1/13/2019, 9:02:15 PM
# Powered by Visual Studio Code
#

s = gets.chomp

for i in 0...s.size
  for j in i...s.size
    if s[0...i] + s[j...s.size] == 'keyence'
      puts "YES"
      exit
    end
  end
end

puts "NO"