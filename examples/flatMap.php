<?php

    function flatMap($in, $cb) {
        if (empty($in)) return array();
        else {
            $x = $cb(array_shift($in));
            if (!is_array($x)) {
                $x = array($x);
            }
            return array_merge($x, flatMap($in, $cb));
        }
    }

    function foo($x) {
        return array($x, $x + 1);
    }

    function bar($x) {
        return $x;
    }

    print_r(flatMap(array(1,2,3), 'foo'));
    print_r(flatMap(array(1,2,3), 'bar'));
