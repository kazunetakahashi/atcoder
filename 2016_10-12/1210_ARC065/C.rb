words = ['dreameraser', 'dreamerase', 'dreamer', 'eraser', 'dream', 'erase']

s = gets.chomp

while s != ""
  ok = false
  words.each{|w|
    if s.start_with?(w)
      ok = true
      s.slice!(0, w.size())
      break
    end
  }
  if !ok
    puts "NO"
    exit
  end
end

puts "YES"
