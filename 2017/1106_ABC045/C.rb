
@sum = 0

def dfs(s, pos)
  if s.size() >= pos
    puts s
    @sum += eval(s)
  else
    dfs(s[0...pos] + '+' + s[pos...s.size()], pos+2)
    dfs(s[0...pos] + s[pos...s.size()], pos+1)
  end
end

dfs(gets.chomp, 0)

puts @sum
