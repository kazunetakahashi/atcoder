#
# File    : A.rb
# Author  : Kazune Takahashi
# Created : 2018-7-15 15:12:00
# Powered by Visual Studio Code
#

n = gets.to_i
a = gets.chomp.split(" ").map{|i| i.to_i}

ary = []
while !a.empty?
  for i in 0...a.size()
    if a[i] != a[i+1]
      puts a[0..i]
      ary << a[0..i]
      a = a[i+1..-1]
      break
    end
    ary << a
    a = []
  end
end

p ary

ans = 0

ary.each{|it|
  ans += it.size / 2
}

puts ans