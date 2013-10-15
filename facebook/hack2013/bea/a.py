import string

T=int(raw_input())
for t in xrange(T):
	line=raw_input()
	cl=[0 for i in xrange(26)]
	for c in line:
		c=c.lower()
		if c not in string.lowercase: continue
		cl[ord(c)-ord('a')]+=1
	#sorted(cl)
	cl.sort()
	#print cl
	s=0
	for i in xrange(1,27):
		s+=i*cl[i-1]
	print 'Case #%d: %d'%(t+1, s)

