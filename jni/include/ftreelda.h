//
//  ftreelda.h
//  cpp_test
//
//  Created by yulele on 16/9/8.
//  Copyright (c) 2016年 yulele. All rights reserved.
//

#ifndef __cpp_test__ftreelda__
#define __cpp_test__ftreelda__

#include <stdio.h>
#include <iostream>
#include <vector>
#include <unordered_map>
#include "ftree.h"
#include "csr.h"
#include "traverse_map.h"

namespace lda {


class ftreelda {
public:
    int _D, _V, _K;
    float _alpha, _beta, _vbeta;
    
    int * _ws, * _dids;
    int * _topics;
    
    adj_list * _adj;
    
    traverse_map * _ndk;
    ftree _tree;
    
    float * _p;
    int * _wk;
    int * _nk;
    int * _t_idx;
    double _ll;
    
    ftreelda(int D, int V, int K,
             float alpha, float beta,
             adj_list * adj): _tree(K) {
        _D = D;
        _V = V;
        _K = K;
        _alpha = alpha;
        _beta = beta;
        _vbeta = V * beta;
        _ws = adj->_ws;
        _dids = adj->_dids;
        _topics = adj->_topics;
        _ndk = new traverse_map[_D];
        _adj = adj;
        
        _p = new float[_K];
        _wk = new int[_K];
        _nk = new int[_K];
        _t_idx = new int[_K];
        
    }
    
    ~ftreelda() {
        delete _adj;
        delete [] _ndk;
    }
    
    
    void init();
    void train_one_word(int w);
    void train_one_iteration(int it);
    

};
    
}

#endif /* defined(__cpp_test__ftreelda__) */
