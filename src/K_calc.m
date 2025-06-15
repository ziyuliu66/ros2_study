function K = K_calc()
   
    syms x(t) T R Iw mw L theta(t) mp g Ip 
    syms f1 f2 d_theta d_x theta0 x0  

    lw=0.5/2;                        %摆杆质心高度（以轮轴为原点）
    lb=0.5+0.09;                     %机体质心高度
    R1=0.1;                          %驱动轮半径
    mw1=1.18;                        %驱动轮质量
    mb=5;                            %机体质量
    ml=0.8;                          %摆杆质量
    mp1=mb+ml;                       %杆质量+机体
    L1=(lb*mb+lw*ml)/mp1;            %总重心到驱动轮轴距离
    Iw1=mw1*R1^2;                    %驱动轮转动惯量
    Ip1=mb*(lb-L1)^2+ml*(L1-lw)^2;   %摆杆转动惯量
   
    N = mp*diff(x + L*sin(theta),t,2);
    P = mp*g+mp*diff(L*cos(theta),t,2);

    eqn1 = diff(x,t,2) == (T -N*R)/(Iw/R + mw*R);
    eqn2 = Ip*diff(theta,t,2) == P*L*sin(theta)-N*L*cos(theta)-T;
   
    
    eqn10 = subs(subs(subs(subs(subs(subs(subs(eqn1,diff(theta,t,2),f1),diff(x,t,2),f2)),diff(theta,t),d_theta),diff(x,t),d_x),theta,theta0),x,x0);
    eqn20 = subs(subs(subs(subs(subs(subs(subs(eqn2,diff(theta,t,2),f1),diff(x,t,2),f2)),diff(theta,t),d_theta),diff(x,t),d_x),theta,theta0),x,x0);
  

    [f1,f2] = solve(eqn10,eqn20,f1,f2);
   
    A=subs(jacobian([d_theta,f1,d_x,f2],[theta0,d_theta,x0,d_x,]),[theta0,d_theta,d_x,T],[0,0,0,0]);
    A=subs(A,[R,L,mw,mp,Iw,Ip,g],[R1,L1,mw1,mp1,Iw1,Ip1,9.8]);
    A=double(A);
    B=subs(jacobian([d_theta,f1,d_x,f2],T),[theta0,d_theta,d_x,T],[0,0,0,0]);
    B=subs(B,[R,L,mw,mp,Iw,Ip,g],[R1,L1,mw1,mp1,Iw1,Ip1,9.8]);
    B=double(B);
    
    Q=diag([1000 100 1500 100]);%theta d_theta x d_x %700 1 600 200 
    R=50;                            %T 
    
    K=lqr(A,B,Q,R);
  
end