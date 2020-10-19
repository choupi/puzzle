# 68. Text Justification
# https://leetcode.com/problems/text-justification/

class Solution(object):
    def fullJustify(self, words, maxWidth):
        """
        :type words: List[str]
        :type maxWidth: int
        :rtype: List[str]
        """
        res=[]
        word_list=[]
        idx=0
        cnt=0
        while idx<len(words):
            wl=len(words[idx])
            if cnt+wl+len(word_list)<=maxWidth:
                cnt+=wl
                word_list.append(words[idx])
                idx+=1
                continue
            else:
                if len(word_list)>1: 
                    nspace=(maxWidth-cnt)/(len(word_list)-1)
                    nword=(maxWidth-cnt)%(len(word_list)-1)
                else: 
                    nspace=(maxWidth-cnt)-1
                    nword=1
                s=''
                for i, w in enumerate(word_list):
                    if i<nword: s+=word_list[i]+' '*(nspace+1)
                    elif i<len(word_list)-1: s+=word_list[i]+' '*nspace
                    else: s+=word_list[i]
                res.append(s)
                #s=s.join(word_list[1:])
                #nspace=maxWidth-len(s)-len(word_list[0])
                #s=word_list[0]+' '*nspace+s
                #res.append(s)
                word_list=[]
                cnt=0
        s=' '.join(word_list)
        res.append(s+' '*(maxWidth-len(s)))
        return res
