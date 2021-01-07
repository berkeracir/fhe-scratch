/*
    (C) Copyright 2019 CEA LIST. All Rights Reserved.
    Contributor(s): Cingulata team (formerly Armadillo team)

    This software is governed by the CeCILL-C license under French law and
    abiding by the rules of distribution of free software.  You can  use,
    modify and/ or redistribute the software under the terms of the CeCILL-C
    license as circulated by CEA, CNRS and INRIA at the following URL
    "http://www.cecill.info".

    As a counterpart to the access to the source code and  rights to copy,
    modify and redistribute granted by the license, users are provided only
    with a limited warranty  and the software's author,  the holder of the
    economic rights,  and the successive licensors  have only  limited
    liability.

    The fact that you are presently reading this means that you have had
    knowledge of the CeCILL-C license and that you accept its terms.
*/

#include <iostream>

/* local includes */
#include <tfhe_bit_exec.hxx>
#include <ci_context.hxx>
#include <ci_int.hxx>


/* namespaces */
using namespace std;
using namespace cingulata;

int main() {
  /* Only tfhe bit executor is needed for encryption/decryption and IO operations  */
  CiContext::set_bit_exec(make_shared<TfheBitExec>("tfhe.sk", TfheBitExec::Secret));

  CiInt alpha{0, 16, false};
  CiInt beta1{0, 16, false};
  CiInt beta2{0, 16, false};
  CiInt beta3{0, 16, false};


  alpha.read("alpha").decrypt();
  beta1.read("beta1").decrypt();
  beta2.read("beta2").decrypt();
  beta3.read("beta3").decrypt();

  cout << "alpha:" << alpha.get_val() << endl;
  cout << "beta1:" << beta1.get_val() << endl;
  cout << "beta2:" << beta2.get_val() << endl;
  cout << "beta3:" << beta3.get_val() << endl;
}
