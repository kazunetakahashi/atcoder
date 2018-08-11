#
# File    : B.rb
# Author  : Kazune Takahashi
# Created : 2018-8-11 21:01:18
# Powered by Visual Studio Code
#

n = gets.to_i

ary = Array.new(1000){false}

ary[0] = true

for i in 0...1000
  if ary[i]
    ary[i + 4] = true
    ary[i + 7] = true
  end
end

if ary[n]
  puts "Yes"
else
  puts "No"
end