'''
'''

import os
from datetime import datetime

def format():

    arr = []

    return arr

fn = "cme_globex30_Snap_310_A_20190213.pcap.gz"

def get_path_name(file_name):

    def get_provider_name(fn) -> str:

        
        provider_pos = fn.lower().find("incr")

        if provider_pos == -1:
            provider_pos = fn.lower().find("snap")

        provider = fn[0:provider_pos-1]

        return provider

    def parse_rec_date(fn):
        start = fn.find("_A_")
        stop = fn.find("pcap.gz")
        dt_str = fn[start+3:stop-1]
        dt = datetime.strptime(dt_str, '%Y%m%d')

        return dt

    def get_path_date(fn) -> str:

        dt = parse_rec_date(fn)

        yr = '{:04}'.format(dt.year)
        mon = '{:02}'.format(dt.month)
        d = '{:02}'.format(dt.day)

        return f'{yr}/{mon}/{d}'

    provider = get_provider_name(file_name)
    rec_date = get_path_date(fn)

    return f'{provider}/{rec_date}/{fn}'

out_path = get_path_name(fn)

assert out_path == 'cme_globex30/2019/02/12/cme_globex30_Incr_310_A_20190212.pcap.gz'

print(out_path)