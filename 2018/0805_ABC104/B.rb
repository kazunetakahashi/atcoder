#
# File    : B.rb
# Author  : Kazune Takahashi
# Created : 2018-8-5 21:01:39
# Powered by Visual Studio Code
#

s = gets.chomp

if s[0] != 'A'
  puts "WA"
else
  cnt = 0
  s[2..-2].chars{|c|
    if c == 'C'
      cnt += 1
    end
  }
  if cnt != 1
    puts "WA"
  else
    t = s.downcase
    for i in 1...s.size
      if s[i] != t[i] && s[i] != 'C'
        puts "WA"
        exit
      end
    end
  end
  puts "AC"
end
