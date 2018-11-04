#
# File    : B.rb
# Author  : Kazune Takahashi
# Created : 2018-11-4 16:38:39
# Powered by Visual Studio Code
#

x = gets.to_i
ok = Array.new(1010){false}
ok[0] = ok[1] = true

for i in 2...1010 do
  for j in 2...1010 do
    if i ** j < 1010
      ok[i ** j] = true;
    else
      break
    end
  end
end

for i in 0...1010 do
  if ok[x - i]
    puts x - i
    exit
  end
end