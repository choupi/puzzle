

class Solution(object):
    def compareVersion(self, version1, version2):
        """
        :type version1: str
        :type version2: str
        :rtype: int
        """
        v1_spl=version1.split('.')
        v2_spl=version2.split('.')
        if len(v1_spl)<len(v2_spl): v1_spl+=['0']*(len(v2_spl)-len(v1_spl))
        elif len(v2_spl)<len(v1_spl): v2_spl+=['0']*(len(v1_spl)-len(v2_spl))
        for i in range(len(v1_spl)):
            if int(v1_spl[i])>int(v2_spl[i]): return 1
            elif int(v2_spl[i])>int(v1_spl[i]): return -1
        return 0
