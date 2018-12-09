#
# File    : B.rb
# Author  : Kazune Takahashi
# Created : 12/9/2018, 10:29:31 PM
# Powered by Visual Studio Code
#

s = gets.chomp

hash = {}

s.chars{|c|
  if hash.has_key?(c)
    hash[c] += 1
  else
    hash[c] = 1
  end
}

hash.each{|key, val|
  if val % 2 != 0
    puts "No"
    exit
  end
}

puts "Yes"