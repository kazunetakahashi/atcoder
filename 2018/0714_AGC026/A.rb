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
  sep = false
  for i in 0...a.size()
    if a[i] != a[i+1]
      ary << a[0..i]
      a = a[i+1..-1]
      sep = true
      break
    end
  end
  if !sep
    ary << a
    a = []
  end
end

# p ary

ans = 0

ary.each{|it|
  ans += it.size / 2
}

puts ans